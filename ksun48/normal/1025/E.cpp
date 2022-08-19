#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

typedef vector<pair<pair<int,int>, pair<int,int> > > vpp;
typedef vector<pair<pair<int,int>, int > > vp2;
vpp ans[2];
void pr(pair<int,int> x, pair<int,int> y, int swp, int which){
    if(swp){
        ans[which].push_back({{x.second, x.first}, {y.second, y.first}});
    } else {
        ans[which].push_back({x,y});
    }
}

vp2 arr[2];

void dostuff(int swp, int which){
    vp2& a = arr[which];
    for(int i = 0; i < a.size(); i++){
        while(a[i].first.first > i){
            pair<int,int> newloc = {a[i].first.first - 1, a[i].first.second};
            pr(a[i].first, newloc, swp, which);
            a[i].first = newloc;
        }
        while(a[i].first.first < i){
            int z = i;
            while(z + 1 < a.size() && a[z+1].first.first <= a[z].first.first + 1){
                z++;
            }
            for(int b = z; b >= i; b--){
                pair<int,int> newloc = {a[b].first.first + 1, a[b].first.second};
                pr(a[b].first, newloc, swp, which);
                a[b].first = newloc;
            }
        }
    }
}

void dostuff_easy(int swp, int which){
    vp2& a = arr[which];
    for(int i = 0; i < a.size(); i++){
        while(a[i].first.first > i){
            pair<int,int> newloc = {a[i].first.first - 1, a[i].first.second};
            pr(a[i].first, newloc, swp, which);
            a[i].first = newloc;
        }
        while(a[i].first.first < i){
            pair<int,int> newloc = {a[i].first.first + 1, a[i].first.second};
            pr(a[i].first, newloc, swp, which);
            a[i].first = newloc;
        }
    }
}


void bubble_sort1(vp2& a){
    for(int s = 0; s < a.size(); s++){
        for(int t = 0; t + 1 < a.size(); t++){
            if(a[t].first.first > a[t+1].first.first){
                swap(a[t], a[t+1]);
            }
        }
    }
}

void bubble_sort2(vp2& a){
    for(int s = 0; s < a.size(); s++){
        for(int t = 0; t + 1 < a.size(); t++){
            if(a[t].second > a[t+1].second){
                swap(a[t], a[t+1]);
            }
        }
    }
}

void switch_coords(vp2& a){
    for(int s = 0; s < a.size(); s++){
        swap(a[s].first.first, a[s].first.second);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int j = 0; j < 2; j++){
        vp2& a = arr[j];
        a.resize(m);
        for(int i = 0; i < m; i++){
            cin >> a[i].first.first >> a[i].first.second;
            a[i].first.first--;
            a[i].first.second--;
            a[i].second = i;
        }
        bubble_sort1(a);
        dostuff(0, j);
        switch_coords(a);

        bubble_sort1(a);
        dostuff(1, j);
        switch_coords(a);
        
        bubble_sort2(a);

        dostuff_easy(0, j);
        switch_coords(a);

        dostuff_easy(1, j);
        switch_coords(a);
    }
    
    cout << ans[0].size() + ans[1].size() << '\n';
    for(int j = 0; j < ans[0].size(); j++){
        cout << 1 + ans[0][j].first.first << " ";
        cout << 1 + ans[0][j].first.second << " ";
        cout << 1 + ans[0][j].second.first << " ";
        cout << 1 + ans[0][j].second.second << '\n';
    }
    reverse(ans[1].begin(), ans[1].end());
    for(int j = 0; j < ans[1].size(); j++){
        cout << 1 + ans[1][j].second.first << " ";
        cout << 1 + ans[1][j].second.second << " ";
        cout << 1 + ans[1][j].first.first << " ";
        cout << 1 + ans[1][j].first.second << '\n';
    }
}