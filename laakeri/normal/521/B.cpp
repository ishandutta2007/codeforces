#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

map<pair<int, int>, int> cb;

ll mod=1e9+9;

int cx[100011];
int cy[100011];
int r[100011];

int cnt(int i){
    int c=0;
    if (cy[i]==0) return 0;
    for (int ii=-1;ii<=1;ii++){
        if (cb[{cx[i]+ii, cy[i]-1}]>0&&r[cb[{cx[i]+ii, cy[i]-1}]-1]==0) c++;
    }
    return c;
}

int okr(int i){
    if (r[i]==1) return 0;
    for (int ii=-1;ii<=1;ii++){
        if (cb[{cx[i]+ii, cy[i]+1}]>0){
            if (r[cb[{cx[i]+ii, cy[i]+1}]-1]==0&&cnt(cb[{cx[i]+ii, cy[i]+1}]-1)==1){
                return 0;
            }
        }
    }
    return 1;
}

set<int> to;

void rem(int i){
    for (int ii=-1;ii<=1;ii++){
        if (cb[{cx[i]+ii, cy[i]-1}]>0){
            if (okr(cb[{cx[i]+ii, cy[i]-1}]-1)){
                to.insert(cb[{cx[i]+ii, cy[i]-1}]-1);
            }
        }
    }
}

vector<ll> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>cx[i]>>cy[i];
        cb[{cx[i], cy[i]}]=i+1;
    }
    for (int i=0;i<n;i++){
        if (okr(i)){
            to.insert(i);
        }
    }
    for (int asd=0;asd<n;asd++){
        if (asd%2==0){
            while (1){
                int th=(*to.rbegin());
                to.erase(th);
                if (okr(th)){
                    //cout<<th<<"a "<<endl;
                    r[th]=1;
                    v.push_back(th);
                    rem(th);
                    break;
                }
            }
        }
        else{
            while (1){
                int th=(*to.begin());
                to.erase(th);
                if (okr(th)){
                    //cout<<th<<" b"<<endl;
                    r[th]=1;
                    v.push_back(th);
                    rem(th);
                    break;
                }
            }
        }
    }
    ll va=0;
    ll k=1;
    for (int i=n-1;i>=0;i--){
        va+=k*v[i];
        va%=mod;
        k*=(ll)n;
        k%=mod;
    }
    cout<<va<<endl;
}