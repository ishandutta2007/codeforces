#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

ll ss[400000];

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,int> > as(n);
    for (int i=0;i<n;i++){
        cin>>as[i].first;
        as[i].second=i+1;
    }
    sort(as.begin(), as.end());
    for (int i=0;i<n;i++){
        ss[i]+=as[i].first;
        ss[i+1]=ss[i];
    }
    ll k;
    cin>>k;
    ll d=n-k;
    ll ps=0;
    ll es=0;
    for (int i=n-d;i<n;i++){
        ps+=i*as[i].first-ss[i-1];
    }
    ll mav=ps;
    //cout<<es<<" "<<ps<<endl;
    int mavi=-1;
    ll su=0;
    for (int i=0;i<d;i++){
        ps-=(n-d+i)*as[n-d+i].first-ss[n-d+i-1];
        es+=(ss[n-d+i]-ss[i])-k*as[i].first;
        es+=as[n-d+i].first*i-su;
        su+=as[i].first;
        //cout<<es<<endl;
        //cout<<ps<<endl;
        if (es+ps>mav){
            mav=es+ps;
            mavi=i;
        }
        //cout<<es<<" "<<ps<<endl;
    }
    for (int i=mavi+1;i<=mavi+k;i++){
        cout<<as[i].second<<" ";
    }
}