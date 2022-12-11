#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
bool ch[2][MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,Q,cnt=0;
    cin >> N >> Q;
    for(int i=0; i<Q; i++){
        int r,c;
        cin >> r >> c;
        r--;
        if(ch[r][c]){
            if(ch[1-r][c]) cnt--;
            if(c<N&&ch[1-r][c+1]) cnt--;
            if(c>1&&ch[1-r][c-1]) cnt--;
        }
        else{
            if(ch[1-r][c]) cnt++;
            if(c<N&&ch[1-r][c+1]) cnt++;
            if(c>1&&ch[1-r][c-1]) cnt++;
        }
        ch[r][c] = !ch[r][c];
        if(cnt) cout << "No\n";
        else cout << "Yes\n";
    }
}