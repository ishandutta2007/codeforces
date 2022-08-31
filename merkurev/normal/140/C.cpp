#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
multiset <int> q;
set <int> kq;
set <pair<int,int> > p;
vector <pair<int,pair<int,int> > > rez;
pair<int,pair<int,int> > make_str(int x1,int x2,int x3)
{
    if (x1<x2) swap(x1,x2);
    if (x1<x3) swap(x1,x3);
    if (x2<x3) swap(x2,x3);
    return make_pair(x1,make_pair(x2,x3)); 
}
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.insert(x);
        kq.insert(x);
    }
    for (set<int>::iterator i=kq.begin();i!=kq.end();i++)
    {
        int x=*i;
        int xx=q.count(x);
        pair <int,int> qw=make_pair(xx,x);
        p.insert(qw);
    }
    pair<int,int> x1,x2,x3;
    if (p.size()<3) 
    {
        cout<<"0";
        return 0;
    }
    do
    {
        x1=*(p.rbegin());
        p.erase(x1);
        x2=*(p.rbegin());
        p.erase(x2);
        x3=*(p.rbegin());
        p.erase(x3);
        rez.push_back(make_str(x1.second,x2.second,x3.second));
        if (x1.first>1)
            p.insert(make_pair(x1.first-1,x1.second));
        if (x2.first>1)
            p.insert(make_pair(x2.first-1,x2.second));
        if (x3.first>1)
            p.insert(make_pair(x3.first-1,x3.second));
        
    }
    while (p.size()>2);
    
    cout<<rez.size()<<endl;
    for (int i=0;i<rez.size();i++)
        cout<<rez[i].first<<" "<<rez[i].second.first<<" "<<rez[i].second.second<<endl;
    
    return 0;
}