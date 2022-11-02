#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;
typedef pair<int,int> pii;

int N,D,F,X,Y;
vector <int> nm,list;
vector <pii> ma;

int GM(int fuel)
{
    int i,re=0;
    lld sum=0,cap=0;
    for (i=0;i<ma.size();i++){
        if (sum+ma[i].first > fuel) break;
        sum += ma[i].first;
        cap += ma[i].second; re++;
    }
    list = nm;
    for (;i<ma.size();i++) list.push_back(ma[i].second);
    sort(list.begin(),list.end());
    for (i=list.size();i--&&cap>0;){
        cap += list[i]-1;
        re++;
    }
    return re;
}

void proc()
{
    int s,e,m,mx,min_fuel;
    mx = GM(F);
    s = 0, e = F;
    while (s <= e){
        m = (s+e)>>1;
        if (GM(m) == mx) e = m-1, min_fuel = m;
        else s = m+1;
    }
    if (X < mx || X == mx && Y > min_fuel)
        X = mx, Y = min_fuel;
}

int main()
{
    int i,c,f,d;
    scanf("%d%d%d",&N,&D,&F);
    for (i=1;i<=N;i++){
        scanf("%d%d%d",&c,&f,&d);
        if (d < D) nm.push_back(c);
        else ma.push_back(pii(f,c));
    }
    sort(ma.begin(),ma.end());
    proc();
    for (i=0;i<ma.size();i++) if (ma[i].second > 0){
        swap(ma[0],ma[i]);
        sort(ma.begin()+1,ma.end());
        proc();
        break;
    }
    printf("%d %d",X,Y);
}