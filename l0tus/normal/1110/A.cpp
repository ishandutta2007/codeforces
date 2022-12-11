#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 1e6+5;
const int INF = 1e9;

int A[MN],B[MN],N,M,K,cnt,tmp,ans,val;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    //freopen("C:\\Users\\user\\Desktop\\input.txt","r",stdin);
    cin >> M >> K;
    for(int i=1; i<K; i++){
        cin >> cnt;
        ans += cnt*(M%2);
    }
    cin >> cnt;
    ans += cnt;
    if(ans%2) cout << "odd";
    else cout << "even";
}