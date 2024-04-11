#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define F first
#define S second

using namespace std;

struct st{
    int id,a,p;
    bool operator<(const st& s) const{
        return a>s.a;
    }
};

vector<st> sts;

vector<pair<int,int> > bs;

int s;

int v[100002];

int test (int d, int pr=0){
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > dudes;
    int i=0;
    int pay=0;
    for (int b=0;b<bs.size();b+=d){
        if (i<sts.size()){
            while (sts[i].a>=bs[b].F){
                dudes.push(make_pair(sts[i].p, sts[i].id));
                i++;
                if (i==sts.size()){
                    break;
                }
            }
        }
        if (dudes.empty()){
            return 0;
        }
        pay+=dudes.top().F;
        if (pr){
            for (int bb=b;bb<b+d&&bb<bs.size();bb++){
                v[bs[bb].S]=dudes.top().S;
            }
        }
        dudes.pop();
        if (pay>s){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n,m;
    cin>>n>>m>>s;
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        bs.push_back(make_pair(a, i+1));
    }
    for (int i=0;i<n;i++){
        st ss;
        ss.id=i+1;
        cin>>ss.a;
        sts.push_back(ss);
    }
    for (int i=0;i<n;i++){
        cin>>sts[i].p;
    }
    sort(sts.begin(), sts.end());
    sort(bs.rbegin(), bs.rend());
    int a=1;
    int b=m;
    while (a<=b){
        int mi=(a+b)/2;
        if (test(mi)){
            b=mi-1;
        }
        else{
            a=mi+1;
        }
    }
    if (a>m){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        test(a,1);
        for (int i=1;i<=m;i++){
            cout<<v[i]<<" ";
        }
    }
}