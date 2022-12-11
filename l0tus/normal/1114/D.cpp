#include <bits/stdc++.h>
using namespace std;
const int MN = 5010;
int N,A[MN],cnt=1,pos,D[MN][MN],tmp,ans;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[cnt];
        if(A[cnt]==A[cnt-1]) cnt--;
        cnt++;
    }
    cnt--;
    for(int pos = cnt; pos>=1; pos--){
        for(int i=0; i<=pos-1; i++){
            tmp = 0;
            if(i) tmp = max(tmp,D[i-1][cnt-pos+1]);
            tmp = max(tmp,D[i][cnt-pos]);
            if(i>=2 && A[i-1]==A[pos]) tmp = max(tmp,D[i-1][cnt-pos]+1);
            D[i][cnt-pos+1] = tmp;
            ans = max(ans,tmp);
        }
    }
    cout << cnt-1-ans;
}