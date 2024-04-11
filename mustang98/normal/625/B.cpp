#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
int main()
{
    char s1[100005];
    char s2[100];
    cin>>s1;
    cin>>s2;
    ll l1=0,l2=0;
    char *p1=s1;
    //while(*p1) {l1++; p1++;};
    p1 = s2;
    while(*p1) {l2++; p1++;};
    //cout<<l2<<endl;
    ll res=0;
    char *p = strstr(s1,s2);
    while (p!=NULL)
    {
        res++;
        *(p+l2-1)='#';
        p = strstr(p+1,s2);
    }
    cout<<res;
    return 0;
}