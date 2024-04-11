# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> atk, def, cur;
vector<pair<int,int> >sol;
int ans = 0;

void solve_only_attack()
{
    int pos = cur.size()-1;
    for(int i=0; i<atk.size(); i++)
    {
        if (pos<0 || cur[pos]<atk[i]) break;
        ans += cur[pos] - atk[i];
        pos--;
    }
}

void solve_all_def()
{
    int res=0;
    if(cur.size() < atk.size() + def.size()) return; 
    
    for(int i=0; i<atk.size(); i++)
        sol.push_back(make_pair(atk[i],0));
    for(int i=0; i<def.size(); i++)
        sol.push_back(make_pair(def[i],2));
    for(int i=0; i<cur.size(); i++)
        sol.push_back(make_pair(cur[i],1));
    sort(sol.begin(), sol.end());
    
    for(int i=0; i<sol.size(); i++)
        if(sol[i].second==2)
        {
            bool flag = true;
            for(int j=i+1; j<sol.size(); j++)
                if(sol[j].second==1) {
                    sol[j].second=-1;
                    flag=false; break;
                }
            
            if(flag) return;
        }
    for(int i=0; i<sol.size(); i++)
        if(sol[i].second==0)
        {
            bool flag = true;
            for(int j=i+1; j<sol.size(); j++)
                if(sol[j].second==1) {
                    sol[j].second=-1;
                    res += sol[j].first - sol[i].first;
                    flag = false; break;
                }
            if(flag) return;
        }

    for(int i=0; i<sol.size(); i++)
        if(sol[i].second==1) res+=sol[i].first;
    
    if(res>ans) ans = res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char s[10]; int t;
    for(int i=0; i<n; i++)
    {
        scanf("%s%d",s,&t);
        if(s[0]=='D')
            def.push_back(t);
        else
            atk.push_back(t);
    }
    
    for(int i=0; i<m; i++)
        scanf("%d",&t),
        cur.push_back(t);
    
    sort(def.begin(),def.end());
    sort(atk.begin(),atk.end());
    sort(cur.begin(),cur.end());
    solve_only_attack();
    solve_all_def();
    cout << ans << endl;
    return 0;
}