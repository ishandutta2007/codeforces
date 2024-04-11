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
ll n,m;
string arr[10];
vector<int>s;
int comp(string &a,string &b){
    int ret=0;
    s.clear();
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            ret++;
            s.pb(i);
        }
    }
    return ret;
}
int comp2(string &a,string &b){
    int ret=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            ret++;
        }
    }
    return ret;
}
bool check(string &s){
    for(int i=0;i<n;i++){
        if(comp2(arr[i],s)>1){
            return false;
        }
    }
    return true;
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int oo ;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            oo = comp(arr[i],arr[j]);
            if(oo>2){
                cout<<-1<<"\n";
                return;
            }
            if(oo==2){
                string ooo = arr[i];
                ooo[s[1]]=arr[j][s[1]];
                if(check(ooo)){
                    cout<<ooo<<"\n";
                    return;
                }
                ooo = arr[i];
                ooo[s[0]]=arr[j][s[0]];
                if(check(ooo)){
                    cout<<ooo<<"\n";
                    return;
                }
                cout<<-1<<"\n";
                return;
            }
        }
    }
    cout<<arr[0]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}