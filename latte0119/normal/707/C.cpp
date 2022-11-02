#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


int root(int x){
    int lb=0,ub=1001001001;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(mid*mid<=x)lb=mid;
        else ub=mid;
    }
    if(lb*lb==x)return lb;
    else return -1;
}

signed main(){
    int x;cin>>x;

    if(x<3){
        cout<<-1<<endl;
        return 0;
    }

    if(x%4==0){
        int t=x/4;
        cout<<3*t<<" "<<5*t<<endl;
        return 0;
    }

    for(int m=2;m*m<x;m++){
        int n=root(x-m*m);
        if(n>0&&n<m){
            int a=m*m-n*n;
            int b=2*m*n;
            int c=m*m+n*n;
            if(b>=c||a*a+b*b!=c*c)continue;
            if(x%c)continue;
            int t=x/c;
            cout<<a*t<<" "<<b*t<<endl;
            return 0;
        }
    }

    int y=x;
    while(y%2==0)y/=2;
    for(int i=3;i*i<=y;i++){
        if(y%i==0){
            int a=i;
            int b=a*a/2;
            int c=a*a/2+1;
            int t=x/a;
            cout<<b*t<<" "<<c*t<<endl;
            return 0;
        }
        while(y%i==0)y/=i;
    }

    int t=x/y;
    cout<<y*y/2*t<<" "<<(y*y/2+1)*t<<endl;
    return 0;
}