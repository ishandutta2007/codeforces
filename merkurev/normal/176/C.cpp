#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


int main()
{

    int n,m,x1,x2,y1,y2;
    scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
    int dx=abs(x1-x2);
    int dy=abs(y1-y2);
    if (dx>dy)
        swap(dx,dy);
    if (dx>4 || dy>4 || (dx==4 && dy==4) || (dx==3 && dy==4))
    {
        printf("Second");
        return 0;
    }
    printf("First");

    return 0;
}