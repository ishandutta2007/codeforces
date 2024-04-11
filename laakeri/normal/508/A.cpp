#include <iostream>

using namespace std;

int lol[1100][1100];

int test(int x, int y){
    if (x<0||y<0) return 0;
    if (lol[x][y]==1&&lol[x+1][y]==1&&lol[x][y+1]==1&&lol[x+1][y+1]==1) return 1;
    return 0;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        lol[x][y]=1;
        for (int a=x-1;a<=x;a++){
            for (int aa=y-1;aa<=y;aa++){
                if (test(a, aa)){
                    cout<<i+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<0<<endl;
    return 0;
}