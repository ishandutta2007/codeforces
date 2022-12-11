#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
int N,M,K,dir,xpos,ypos,cnt,x1,x2,y1,y2;
vector<int> X[MN],Y[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M >> K;
    int x,y;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for(int i=1; i<=N; i++){
        //X[i].push_back(0);
        //X[i].push_back(M+1);
        sort(X[i].begin(),X[i].end());
    }
    for(int i=1; i<=M; i++){
        //Y[i].push_back(0);
        //Y[i].push_back(N+1);
        sort(Y[i].begin(),Y[i].end());
    }
    int ch=0,tmp;
    ll sum = 1;
    xpos = ypos = dir = 1;
    x1 = 0, x2 = N+1, y1 = 0, y2 = M+1;
    while(ch<1){
        //cout << xpos << ' ' << ypos << '\n';
        if(dir==1){
            cnt = lower_bound(X[xpos].begin(),X[xpos].end(),ypos)-X[xpos].begin();
            if(cnt==X[xpos].size()) tmp = y2-1;
            else tmp = min(X[xpos][cnt]-1,y2-1);
            //cout << cnt << tmp;
            if(tmp==ypos){
                if(xpos!=1||ypos!=1) ch++;
            }
            sum += tmp-ypos;
            ypos = tmp;
            x1 = xpos;
        }
        if(dir==2){
            cnt = lower_bound(Y[ypos].begin(),Y[ypos].end(),xpos)-Y[ypos].begin();
            if(cnt==Y[ypos].size()) tmp = x2-1;
            else tmp = min(Y[ypos][cnt]-1,x2-1);
            if(tmp==xpos) ch++;
            sum += tmp-xpos;
            xpos = tmp;
            y2 = ypos;
        }
        if(dir==3){
            cnt = lower_bound(X[xpos].begin(),X[xpos].end(),ypos)-X[xpos].begin();
            if(cnt==0) tmp = y1+1;
            else tmp = max(X[xpos][cnt-1]+1,y1+1);
            if(tmp==ypos) ch++;
            sum += ypos-tmp;
            ypos = tmp;
            x2 = xpos;
        }
        if(dir==4){
            cnt = lower_bound(Y[ypos].begin(),Y[ypos].end(),xpos)-Y[ypos].begin();
            if(cnt==0) tmp = x1+1;
            else tmp = max(Y[ypos][cnt-1]+1,x1+1);
            if(tmp==xpos) ch++;
            sum += xpos-tmp;
            xpos = tmp;
            y1 = ypos;
        }
        dir = dir%4+1;
    }
    //cout << sum;
    if(sum+K==(ll)N*M) cout << "Yes";
    else cout << "No";
}