#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxDim = 105;
const int MaxK = 105;

char board[MaxK][MaxK];
int N, M, K;
bool canRLose, canGLose;
bool anyR, anyG;

void input(){
	scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < N; i++)
        scanf("%s", board[i]);
}

int main(){
	input();
    canRLose = canGLose = true;
    anyR = anyG = false;

    vector<int> stacks;

    for(int r = 0; r < N; r++){
        bool hasFree = false, hasR = false, hasG = false;
        int occurR = -1, occurC = -1;

        for(int c = 0; c < M; c++){
            switch(board[r][c]){
                case 'R': hasR = true; occurR = c; anyR = true; break;
                case 'G': hasG = true; occurC = c; anyG = true; break;
                case '-': hasFree = true; break;
            }
        }

        if(hasFree){
            if(hasR && !hasG) canRLose = false;
            if(hasG && !hasR) canGLose = false;
        }

        if(hasR && hasG){
            stacks.push_back(abs(occurR-occurC)-1);
        }
    }

    if(!anyG){
        printf("Second\n"); return 0;
    }
    if(!anyR){
        if(!canGLose)
            printf("First\n");
        else
            printf("Second\n");
        
        return 0;
    }


    vector<int> nimBits(30, 0);
    for(int v: stacks){
        int mask = 1;
        for(int step = 0; step < 30; step++){
            if(v & mask) nimBits[step]++;
            mask *= 2;
        }
    }

    bool isLosing = true;
    for(int i = 0; i < 30; i++)
        if(nimBits[i] % (K+1) != 0)
            isLosing = false;

    
    if(!canRLose && !canGLose){
        printf("Draw\n");
        return 0;
    }
    if(!canRLose || !canGLose){
        if(!canGLose)
            printf("First\n");
        else
            printf("Second\n");
        return 0;
    }

    if(isLosing){
        printf("Second\n");
    } else {
        printf("First\n");
    }

}