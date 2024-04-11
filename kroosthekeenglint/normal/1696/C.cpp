#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int m;
void add_num(vector<pair<int, long long> > &a, int x, long long num)
{
    if (x%m==0)
    {
        add_num(a, x/m, num*m);
    }
    else
    {
        if ((a.size()!=0)&&(a[a.size()-1].first == x))
        {
            a[a.size()-1].second += num;
        }
        else
        {
            a.push_back(make_pair(x,num)); 
        }
    }
}
void read_array(vector<pair<int, long long> > &a,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        add_num(a, x, 1);
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d%d",&n,&m);
        int i;
        vector<pair<int, long long> > a;
        read_array(a,n);
        int k;
        scanf("%d",&k);
        vector<pair<int, long long> > b;
        read_array(b,k);
        if (a.size()!=b.size())
        {
            puts("No");
            continue;
        }
        for (i=0;i<(int)a.size();i++)
        {
            if (a[i]!=b[i])
            {
                puts("No");
                break;
            }
        }
        if (i==(int)a.size())
        {
            puts("Yes");
        }
    }
    return 0;
}