#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <functional>

#define rep(x,y,z) for (int x=(y),e##x=(z);x<e##x;x++)

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    int n;
    cin>>n;
    if ((n&1)==1)
    {
        char curr='a';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='a') curr='b';
            else curr='a';
        }
        printf("z\n");
         curr='c';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='c') curr='d';
            else curr='c';
        }
        printf("z\n");
        printf("y");
         curr='e';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='e') curr='f';
            else curr='e';
        }
        printf("\ny");
         curr='g';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='g') curr='h';
            else curr='g';
        }
    }
    else
    {
        char curr='a';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='a') curr='b';
            else curr='a';
        }
        printf("\n");
         curr='c';
        rep(i,0,n>>1)
        {
            printf("%c%c",curr,curr);
            if (curr=='c') curr='d';
            else curr='c';
        }
        printf("\ny");
         curr='e';
        rep(i,0,(n>>1)-1)
        {
            printf("%c%c",curr,curr);
            if (curr=='e') curr='f';
            else curr='e';
        }
        printf("z\ny");
         curr='g';
        rep(i,0,(n>>1)-1)
        {
            printf("%c%c",curr,curr);
            if (curr=='g') curr='h';
            else curr='g';
        }
        printf("z\n");

    }
    return 0;
}