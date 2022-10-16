#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
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
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for(int i=1;i<=s.size();i++){
        set<string>in;
        for(int j=0;j<s.size()-i+1;j++){
            in.insert(s.substr(j,i));
            //cout<<s.substr(j,i)<<"\n";
        }
        string curr = "";
        for(int j=0;j<i;j++){
            curr+='a';
        }
        while(true){
            if(in.find(curr)==in.end()){
                cout<<curr<<"\n";
                return;
            }
            int j = i-1;
            while(j>=0){
                if(curr[j]!='z'){
                    curr[j] = curr[j]+1;
                    break;
                }else{
                    curr[j]='a';
                    j--;
                }
            }
            if(j==-1){
                break;
            }
        }
    }
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