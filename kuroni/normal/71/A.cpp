#include <bits/stdc++.h>

using namespace std;

main()
{
    char s[100];
    int n,i;
    scanf("%d \n",&n);
    for (i=0;i<n;i++)
    {
        cin.getline(s,101);
        if (strlen(s) <= 10) cout<<s<<endl; else cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;
    }
}