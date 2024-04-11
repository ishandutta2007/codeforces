#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n, p[nax], ct[nax * 3];
void no(){
    printf("0 0 0\n");
}

void solve(){
    scanf("%d", &n);
    vector<pair<int, int > > v;
    map<int, int, greater<int>> ct;
    for(int i = 1 ;i <= n; i ++){
        scanf("%d", p + i);
        ct[p[i]] ++ ;
    }
    for(auto it: ct){
        v.emplace_back(it);
      //  printf("%d %d\n", it.first, it.second);
    }
    if((int)v.size() < 3){
        no();
        return;
    }
    int lim = n / 2 ;
    int sum = v[0].second  + v[1].second + v[2].second;
    if(sum > lim){
        no();
        return;
    }
    int a = v[0].second ,b = v[1].second;
    int now = 2;
    while(b <= a){
        if(now >= (int)v.size())break;
        b += v[now].second;
        now ++;
    }
    if(now >= (int)v.size()){
        no();
        return ;
    }
    int c = 0;
    while(c <= a){
        if(now >= (int)v.size()) break;
        c += v[now].second;
        now ++;
    }
    if(now >= (int)v.size()){
        no();
        return ;
    }
    if(a + b + c > lim){
        no();
        return ;
    }
    while(a + b + c <= lim){
        if(now >= (int)v.size()) break;
        if(a + b + c + v[now].second > lim)break;
        c += v[now].second;
        now ++;
    }
    printf("%d %d %d\n", a, b, c);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/