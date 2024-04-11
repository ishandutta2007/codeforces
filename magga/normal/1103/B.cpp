#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void query(int x,int y){
    cout<<"?"<<" "<<x<<" "<<y<<"\n";
    cout.flush();
}
void answer(int a){
    cout<<"! "<<a<<"\n";
    cout.flush();
}
void solve(){
    ll x = 1;
    ll y = 2;
    char s;
    while(true){
        query(x,y);
        cin>>s;
        if(s=='x'){
            break;
        }else{
            x*=2;
            y*=2;
        }
    }
    if(x==1){
        query(0,1);
        cin>>s;
        if(s=='x'){
            answer(1);
        }else{
            answer(2);
        }
        return;
    }
    ll start = x,end = y-1,mid,ans=x+1;
    while(start<=end){
        mid = (start+end+1)/2;
        query(x,mid);
        cin>>s;
        if(s=='y'){
            start=mid+1;
            ans=mid+1;
        }else{
            end = mid-1;
        }
    }
    answer(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    string s;
    while(true){
        cin>>s;
        if(s!="start"){
            break;
        }
       	solve();
    }   
}