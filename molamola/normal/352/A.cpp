#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int n, a, b;

int main()
{
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x == 0)a++;
        else b++;
    }
    b /= 9;
    b *= 9;
    if(a == 0){printf("-1");return 0;}
    if(b == 0){
        printf("0");return 0;
    }
    
    for(i=0;i<b;i++)printf("5");
    for(i=0;i<a;i++)printf("0");
    return 0;
}