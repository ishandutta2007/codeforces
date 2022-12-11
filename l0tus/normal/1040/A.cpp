#include <bits/stdc++.h>
using namespace std;
int N,A,B,C[21],ans=0;
int main()
{
    cin >> N >> A >> B;
    for(int i=0; i<N; i++)
        cin >> C[i];
    for(int i=0; i<N; i++)
    {
        if(C[i]!=2)
        {
            if(C[N-1-i]==2) continue;
            if(C[i]!=C[N-1-i])
            {
                cout << -1;
                return 0;
            }
        }
        else
        {
            if(C[N-1-i]==2)
            {
                if(2*i+1 == N) ans += min(A,B);
                else ans += 2*min(A,B);
                C[i] = C[N-1-i] = 1;
            }
            else
            {
                if(C[N-1-i]==1)
                {
                    ans += B;
                    C[i] = 1;
                }
                else
                {
                    ans += A;
                    C[i] = 0;
                }
            }
        }
    }
    cout << ans;
}