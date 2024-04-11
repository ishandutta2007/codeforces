%:include<cstdio>
%:define int unsigned long long
int n,k;
signed main()
{
    scanf("%I64d%I64d",&n,&k);
    puts((n/k&1)?"YES":"NO");
    return 0;
}