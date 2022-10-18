#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

int main(){
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    FORR(i,a)
        cin >> i;
    FORR(i,b)
        cin >> i;
    int *it1 = a, *it2 = b;
    int res = 0,c1=0,c2=0;
    while(it1 != a+n || it2 != b+m){
        if(it2 == b+m || c1 < c2){
            c1 += *it1++;
        }
        else{
            c2 += *it2++;
        }
        if(c1 == c2){
            ++res;
            c1 = c2 = 0;
        }
    }
    cout << res << '\n';
}