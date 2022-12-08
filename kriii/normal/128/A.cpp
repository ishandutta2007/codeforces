#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int> > E;
int N=8,C[10][10],A[10][10],B[10][10];
char BD[10][10];
int dx[9] = {1,1,1,0,0,0,-1,-1,-1};
int dy[9] = {1,0,-1,1,0,-1,1,0,-1};

int main()
{
    int i,j,k,x,y;

    for (i=0;i<N;i++){
        scanf ("%s",BD[i]);
        for (j=0;j<N;j++){
            if (BD[i][j] == 'S'){
                E.push_back(make_pair(i,j));
                C[i][j]++;
            }
        }
    }

    A[7][0] = 1;
    while (!E.empty()){
        for (i=0;i<N;i++){
            for (j=0;j<N;j++) if (A[i][j]){
                for (k=0;k<9;k++){
                    x = i + dx[k];
                    y = j + dy[k];
                    if (x < 0 || y < 0 || x >= N || y >= N) continue;
                    if (!C[x][y]) B[x][y] = 1;
                }
            }
        }

        for (i=0;i<N;i++) for (j=0;j<N;j++) A[i][j] = B[i][j], B[i][j] = 0;

        for (i=0;i<E.size();i++){
            x = E[i].first; y = E[i].second;
            if (x == 7){
                C[x][y]--; E.erase(E.begin()+i); i--;
            }
            else{
                C[x][y]--; E[i].first++; C[x+1][y]++;
            }
        }

        for (i=0;i<N;i++) for (j=0;j<N;j++) if (C[i][j] && A[i][j]) A[i][j] = 0;
    }

    for (i=0;i<N;i++) for (j=0;j<N;j++) if (A[i][j]){printf ("WIN"); return 0;}
    printf ("LOSE");

    return 0;
}