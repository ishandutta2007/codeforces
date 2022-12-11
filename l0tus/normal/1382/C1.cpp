#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

string A,B,C;
vector<int> ans;

void act(int k)
{
    ans.push_back(k+1);
    C.resize(k+1);
    for(int i=0; i<=k; i++){
        C[i] = A[i];
    }
    for(int i=0; i<=k; i++){
        A[i] = '0'+!(C[k-i]-'0');
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> A >> B;
        ans.clear();
        for(int i=n-1; i>=0; i--){
            if(A[i]==B[i]) continue;
            if(A[0]!=B[i]){
                act(i);
            }
            else{
                act(0);
                act(i);
            }
        }
        cout << ans.size() << ' ';
        for(int x:ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}