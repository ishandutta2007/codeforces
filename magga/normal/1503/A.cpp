 #include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
// Please write the recurances once :(
void pre(){}
bool check(string s){
    int a = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            a++;
        }else{
            a--;
        }
        if(a<0){
            return false;
        }
    }
    return a==0;
}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    int s1 = 0;
    for(auto i:s){
        if(i=='1') s1++;
    }
    if(s1%2==1){
        cout<<"NO"<<"\n";
        return;
    }
    string sa,sb;
    int j = 0;
    bool flag = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(j<s1/2){
                j++;
                sa+='(';
                sb+='(';
            }else{
                j++;
                sa+=')';
                sb+=')';
            }
        }else{
            if(flag){
                sa+='(';
                sb+=')';
            }else{
                sa+=')';
                sb+='(';
            }
            flag = !flag;
        }
    }
    if(check(sa) && check(sb)){
        cout<<"YES"<<"\n";
        cout<<sa<<"\n";
        cout<<sb<<"\n";
    }else{
        cout<<"NO"<<"\n";
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