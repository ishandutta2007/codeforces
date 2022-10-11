#include <bits/stdc++.h>

using namespace std;

main()
{
    char str[200];
    int A[3],zero=0,n,i,marko=0;
    memset(A,0,sizeof(A));
    cin>>n;
    scanf("%s",&str);
    for (i=0;i<n;i++)
    {
        if (str[i] == 'B') A[0]++;
        if (str[i] == 'G') A[1]++;
        if (str[i] == 'R') A[2]++;
    }
    for (i=0;i<3;i++) if (A[i] == 0) {zero++;marko+=i;}
    if (zero == 0) cout<<"BGR";
    if (zero == 2)
    {
        if (marko == 3) cout<<"B"; else if (marko == 2) cout<<"G"; else cout<<"R";
    }
    if (zero == 1)
    {
        int one = 0, markz = 0;
        for (i=0;i<3;i++) if (A[i] == 1) {one++;markz=i;}
        if (one == 0) cout<<"BGR";
        if (one == 2)
        {
            if (marko == 0) cout<<"B"; else if (marko == 1) cout<<"G"; else cout<<"R";
        }
        if (one == 1)
        {
            if (markz < marko)
            {
                int tmp = markz;
                markz = marko;
                marko = tmp;
            }
            if (marko == 0) cout<<"B"; else cout<<"G";
            if (markz == 1) cout<<"G"; else cout<<"R";
        }
    }
}