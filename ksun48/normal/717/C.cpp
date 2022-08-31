#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);
    sort(A.begin(), A.end());
    long long ans=0;
    for(int i=0; i<N; i++)
        ans+=1LL*A[i]*A[N-1-i];
    printf("%lld\n", ans%10007);
    return 0;
}