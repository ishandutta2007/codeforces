    #include<bits/stdc++.h>
    using namespace std;
    int n,m;
    char str[2000000];
    vector<vector<char> > s;
    vector<vector<char> > d;
    vector<vector<int> > dist;
    vector<vector<int> > dist2;
    vector<int> rd;
    vector<char> r;
    vector<pair<int,int> > q;
    char c;
    void bfs() {
        q.clear();
        dist.clear();
        for(int i=0;i<n;i++) {
            rd.clear();
            for(int j=0;j<m;j++) {
                if(s[i][j]=='.') {
                    rd.push_back(0);
                    q.push_back({i,j});
                }
                else rd.push_back(1e9);
            }
            dist.push_back(rd);
        }
        int ind=0;
        while(ind<q.size()) {
            int x=q[ind].first;
            int y=q[ind].second;
            if(x>0 && dist[x-1][y]>dist[x][y]+1) {
                dist[x-1][y]=dist[x][y]+1;
                q.push_back({x-1,y});
            }
            if(x<n-1 && dist[x+1][y]>dist[x][y]+1) {
                dist[x+1][y]=dist[x][y]+1;
                q.push_back({x+1,y});
            }
            if(y>0 && dist[x][y-1]>dist[x][y]+1) {
                dist[x][y-1]=dist[x][y]+1;
                q.push_back({x,y-1});
            }
            if(y<m-1 && dist[x][y+1]>dist[x][y]+1) {
                dist[x][y+1]=dist[x][y]+1;
                q.push_back({x,y+1});
            }
            if(x>0 && y>0 && dist[x-1][y-1]>dist[x][y]+1) {
                dist[x-1][y-1]=dist[x][y]+1;
                q.push_back({x-1,y-1});
            }
            if(x<n-1 && y<m-1 && dist[x+1][y+1]>dist[x][y]+1) {
                dist[x+1][y+1]=dist[x][y]+1;
                q.push_back({x+1,y+1});
            }
            if(y>0 && x<n-1 && dist[x+1][y-1]>dist[x][y]+1) {
                dist[x+1][y-1]=dist[x][y]+1;
                q.push_back({x+1,y-1});
            }
            if(y<m-1 && x>0 && dist[x-1][y+1]>dist[x][y]+1) {
                dist[x-1][y+1]=dist[x][y]+1;
                q.push_back({x-1,y+1});
            }
            ind++;
        }
    }
    void find_trees(int t) {
        d.clear();
        for(int i=0;i<n;i++) {
            r.clear();
            for(int j=0;j<m;j++) {
                if(s[i][j]=='.') r.push_back('.');
                else {
                    if(dist[i][j]>t) r.push_back('X');
                    else r.push_back('.');
                }
            }
            d.push_back(r);
        }
    }
    bool check_fire(int t) {
        q.clear();
        dist2.clear();
        for(int i=0;i<n;i++) {
            rd.clear();
            for(int j=0;j<m;j++) {
                if(d[i][j]=='X') {
                    rd.push_back(0);
                    q.push_back({i,j});
                }
                else rd.push_back(1e9);
            }
            dist2.push_back(rd);
        }
        int ind=0;
        if(q.size()==0) return false;
        while(ind<q.size()) {
            int x=q[ind].first;
            int y=q[ind].second;
            if(x>0 && dist2[x-1][y]>dist2[x][y]+1) {
                dist2[x-1][y]=dist2[x][y]+1;
                if(s[x-1][y]=='.' && dist2[x-1][y]<=t) return false;
                if(s[x-1][y]=='X' && dist2[x-1][y]>t) return false;
                q.push_back({x-1,y});
            }
            if(x<n-1 && dist2[x+1][y]>dist2[x][y]+1) {
                dist2[x+1][y]=dist2[x][y]+1;
                if(s[x+1][y]=='.' && dist2[x+1][y]<=t) return false;
                if(s[x+1][y]=='X' && dist2[x+1][y]>t) return false;
                q.push_back({x+1,y});
            }
            if(y>0 && dist2[x][y-1]>dist2[x][y]+1) {
                dist2[x][y-1]=dist2[x][y]+1;
                if(s[x][y-1]=='.' && dist2[x][y-1]<=t) return false;
                if(s[x][y-1]=='X' && dist2[x][y-1]>t) return false;
                q.push_back({x,y-1});
            }
            if(y<m-1 && dist2[x][y+1]>dist2[x][y]+1) {
                dist2[x][y+1]=dist2[x][y]+1;
                if(s[x][y+1]=='.' && dist2[x][y+1]<=t) return false;
                if(s[x][y+1]=='X' && dist2[x][y+1]>t) return false;
                q.push_back({x,y+1});
            }
            if(x>0 && y>0 && dist2[x-1][y-1]>dist2[x][y]+1) {
                dist2[x-1][y-1]=dist2[x][y]+1;
                if(s[x-1][y-1]=='.' && dist2[x-1][y-1]<=t) return false;
                if(s[x-1][y-1]=='X' && dist2[x-1][y-1]>t) return false;
                q.push_back({x-1,y-1});
            }
            if(x<n-1 && y<m-1 && dist2[x+1][y+1]>dist2[x][y]+1) {
                dist2[x+1][y+1]=dist2[x][y]+1;
                if(s[x+1][y+1]=='.' && dist2[x+1][y+1]<=t) return false;
                if(s[x+1][y+1]=='X' && dist2[x+1][y+1]>t) return false;
                q.push_back({x+1,y+1});
            }
            if(y>0 && x<n-1 && dist2[x+1][y-1]>dist2[x][y]+1) {
                dist2[x+1][y-1]=dist2[x][y]+1;
                if(s[x+1][y-1]=='.' && dist2[x+1][y-1]<=t) return false;
                if(s[x+1][y-1]=='X' && dist2[x+1][y-1]>t) return false;
                q.push_back({x+1,y-1});
            }
            if(y<m-1 && x>0 && dist2[x-1][y+1]>dist2[x][y]+1) {
                dist2[x-1][y+1]=dist2[x][y]+1;
                if(s[x-1][y+1]=='.' && dist2[x-1][y+1]<=t) return false;
                if(s[x-1][y+1]=='X' && dist2[x-1][y+1]>t) return false;
                q.push_back({x-1,y+1});
            }
            ind++;
        }
        return true;
    }
    bool pos(int t) {
        find_trees(t);
        return check_fire(t);
    }
    int main() {
        scanf("%d %d",&n,&m);
        r.clear();
        for(int i=0;i<m+2;i++) r.push_back('.');
        s.push_back(r);
        for(int i=0;i<n;i++) {
            r.clear();
            r.push_back('.');
            scanf("%s",str);
            for(int j=0;j<m;j++) {
                r.push_back(str[j]);
            }
            r.push_back('.');
            s.push_back(r);
        }
        r.clear();
        for(int i=0;i<m+2;i++) r.push_back('.');
        s.push_back(r);
        n+=2;
        m+=2;
        int l=0;
        int r=(min(n,m)+1)/2;
        bfs();
        while(l<r) {
            int mid=(l+r+1)>>1;
            if(pos(mid)) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
        find_trees(l);
        for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) printf("%c",d[i][j]);
            printf("\n");
        }
        return 0;
    }