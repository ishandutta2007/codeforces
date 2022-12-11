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
int st;
bool rev,inv;

void act(int k)
{
    ans.push_back(k+1);
    if(k==0){
        A[st] = !A[st];
        return;
    }
    if(rev) st = st-k;
    else st = st+k;
    rev = !rev;
    inv = !inv;
}

char get(int k)
{
    char res;
    if(rev) res = A[st-k];
    else res = A[st+k];
    if(inv) res = '0'+!(res-'0');
    return res;
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
        st = rev = inv = 0;
        for(int i=n-1; i>=0; i--){
            if(get(i)==B[i]) continue;
            if(get(0)!=B[i]){
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