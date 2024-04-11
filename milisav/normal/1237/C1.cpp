#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int>,pair<int,int> > a[100000];
pair<pair<int,int>,int> o[100000];
int n;
int solve_z(vector<int>& t) {
    int i=0;
    int l=t.size();
    int pv=-1;
    if(l%2==1) {
        pv=t.back();
        t.pop_back();
    }
    while(i<t.size()) {
        printf("%d %d\n",t[i],t[i+1]);
        i+=2;
    }
    return pv;
}
int solve_y(vector<int>& t) {
    int l=0;
    int i=0;
    vector<int> por;
    int pv=-1;
    while(i<t.size()) {
        int j=i+1;
        por.clear();
        por.push_back(t[i]);
        while(j<t.size() && o[t[j]].first.second==o[t[i]].first.second) {
            por.push_back(t[j]);
            j++;
        }
        l=por.size();
        if(l%2==0) solve_z(por);
        else {
            int cv=solve_z(por);
            if(pv==-1) pv=cv;
            else {
                printf("%d %d\n",pv,cv);
                pv=-1;
            }
        }
        i=j;
    }
    if(pv!=-1) return pv;
}
int solve_x(vector<int>& t) {
    int l=0;
    int i=0;
    vector<int> por;
    int pv=-1;
    while(i<t.size()) {
        int j=i+1;
        por.clear();
        por.push_back(t[i]);
        while(j<t.size() && o[t[j]].first.first==o[t[i]].first.first) {
            por.push_back(t[j]);
            j++;
        }
        l=por.size();
        if(l%2==0) solve_y(por);
        else {
            int cv=solve_y(por);
            if(pv==-1) pv=cv;
            else {
                printf("%d %d\n",pv,cv);
                pv=-1;
            }
        }
        i=j;
    }
    if(pv!=-1) return pv;
}
int main() {
    int x,y,z;
    scanf("%d",&n);
    vector<int> por;
    for(int i=1;i<=n;i++) {
        scanf("%d %d %d",&x,&y,&z);
        a[i-1]={{x,y},{z,i}};
        o[i]={{x,y},z};
    }
    sort(a,a+n);
    for(int i=0;i<n;i++) por.push_back(a[i].second.second);
    solve_x(por);
    return 0;
}