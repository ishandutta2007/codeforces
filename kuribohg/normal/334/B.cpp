#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
pair<int,int> a[10];
int main()
{
    for(int i=1;i<=8;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+9);
    if (a[1].second==a[4].second&&
        a[4].second==a[6].second&&
        a[2].second==a[7].second&&
        a[3].second==a[5].second&&
        a[5].second==a[8].second&&
        a[1].first==a[2].first&&
        a[2].first==a[3].first&&
        a[4].first==a[5].first&&
        a[6].first==a[7].first&&
        a[7].first==a[8].first&&
        a[1].first<a[4].first&&
        a[4].first<a[6].first&&
        a[1].second<a[2].second&&
        a[2].second<a[3].second) {puts("respectable");return 0;}
    puts("ugly");
    return 0;
}