#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
const int MN = 1e5+5;
int num[40],A[MN];
bool ch[MN][40];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        int x = A[i], k = 0;
        while(x){
            ch[i][k] = x%2;
            if(ch[i][k]) num[k]++;
            x/=2;
            k++;
        }
    }
    int ans = -1, pos = -1;
    for(int i=0; i<N; i++){
        int res = 0;
        for(int k=0; k<40; k++){
            if(ch[i][k]&&num[k]==1) res += (1<<k);
        }
        if(res>ans) ans = res, pos = i;
    }
    cout << A[pos] << ' ';
    for(int i=0; i<N; i++){
        if(i==pos) continue;
        cout << A[i] << ' ';
    }
}