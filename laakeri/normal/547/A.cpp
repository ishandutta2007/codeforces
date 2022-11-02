#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int s1[1010101];
int s2[1010101];
int s3[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m;
    cin>>m;
    ll h1,a1,x1,y1;
    cin>>h1>>a1>>x1>>y1;
    ll h2,a2,x2,y2;
    cin>>h2>>a2>>x2>>y2;
    ll hh1=h1;
    ll hh2=h2;
    while (1){
        s1[h1]++;
        if (s1[h1]==3){
            break;
        }
        //cout<<h1<<endl;
        h1=(x1*h1+y1)%m;
    }
    while (1){
        s2[h2]++;
        if (s2[h2]==3){
            break;
        }
        //cout<<"h "<<h2<<endl;
        h2=(x2*h2+y2)%m;
    }
    ll t=0;
    while (s1[hh1]<2||s2[hh2]<2){
        if (hh1==a1&&hh2==a2){
            cout<<t<<endl;
            return 0;
        }
        hh1=(x1*hh1+y1)%m;
        hh2=(x2*hh2+y2)%m;
        t++;
    }
    vector<ll> h1s;
    vector<ll> h2s;
    while (s1[hh1]>1){
        h1s.push_back(hh1);
        s1[hh1]=0;
        hh1=(x1*hh1+y1)%m;
    }
    while (s2[hh2]>1){
        h2s.push_back(hh2);
        s2[hh2]=0;
        hh2=(x2*hh2+y2)%m;
    }
    int f=-1;
    for (int i=0;i<(int)h1s.size();i++){
        if (h1s[i]==a1){
            f=i;
            break;
        }
    }
    if (f==-1){
        cout<<-1<<endl;
        return 0;
    }
    t+=f;
    int i2=f%(int)h2s.size();
    while (s3[i2]==0){
        s3[i2]=1;
        if (h2s[i2]==a2){
            cout<<t<<endl;
            return 0;
        }
        t+=(ll)h1s.size();
        i2+=(int)h1s.size();
        i2%=(int)h2s.size();
    }
    cout<<-1<<endl;
}