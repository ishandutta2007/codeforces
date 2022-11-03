#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
int n;
string s;
int b[220];
int main() 
{
    cin>>n>>s;
    if(n==1) return printf("Yes")&0;
    for(int i=0;i<n;i++) 
    {
        b[(int)s[i]]++;
        if(b[(int)s[i]]>=2) {printf("Yes");return 0;}
    }
    printf("No");
    return 0;
}