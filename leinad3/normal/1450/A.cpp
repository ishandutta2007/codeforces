#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
bool cmp(char a, char b)
{
    return a<b;
}
char A[210];
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %s", &n, &A);
        sort(A, A+n, cmp);
        for(i=0;i<n;i++)printf("%c", A[i]);
        puts("");
    }
}