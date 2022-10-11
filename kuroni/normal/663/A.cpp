#include <bits/stdc++.h>
using namespace std;
main()
{
    int p = 1,m = 0,mark = 0;
    char str[1000];
    cin.getline(str,1000);
    for (int i=0;i<strlen(str);i++)
    {
        if (str[i] == '+') p++;
        if (str[i] == '-') m++;
        if (str[i] == ' ') mark = i+1;
    }
    char temp[1000];
    for (int i = mark; i < strlen(str); i++)
    {
        temp[i-mark] = str[i];
    }
    int n = atoi(temp);
    if ((p*n - m < n) || (p - m*n  > n)) cout<<"Impossible";
    else
    {
        cout<<"Possible"<<endl;
        if (p - m < n)
        {
            mark = 1;
            int kek = m + n;
            int a[p];
            for (int i = 0; i < p; i++)
            {
                if (n*(p-i-1) >= kek) a[i] = 1; else a[i] = kek - n*(p-i-1);
                kek = kek - a[i];
            }
            cout<<a[0];
            for (int i = 1; i < strlen(str); i++)
            {
                if (str[i] == '?')
                {
                    if (str[i-2] == '-') cout<<"1"; else
                    {
                        cout<<a[mark];
                        mark++;
                    }
                }
                else cout<<str[i];
            }
        }
        else
        {
            mark = 0;
            int kek = p - n;
            int a[m];
            for (int i = 0; i < m; i++)
            {
                if (n*(m-i-1) >= kek) a[i] = 1; else a[i] = kek - n*(m-i-1);
                kek = kek - a[i];
            }
            cout<<1;
            for (int i = 1; i < strlen(str); i++)
            {
                if (str[i] == '?')
                {
                    if (str[i-2] != '-') cout<<"1"; else
                    {
                        cout<<a[mark];
                        mark++;
                    }
                }
                else cout<<str[i];
            }
        }
    }
}