#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
ll N,A[MN],tmp,cnt;
vector<ll> L[100];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        tmp = A[i], cnt = 0;
        while(tmp%2==0){
            tmp/=2;
            cnt++;
        }
        L[cnt].push_back(A[i]);
    }
    tmp = 0, cnt = 0;
    for(int i=0; i<100; i++){
        if(cnt<L[i].size()) tmp = i, cnt = L[i].size();
    }
    cout << N-cnt << '\n';
    int x = tmp;
    for(int i=0; i<N; i++){
        tmp = A[i], cnt = 0;
        while(tmp%2==0){
            tmp/=2;
            cnt++;
        }
        if(cnt!=x) cout << A[i] << ' ';
    }
}