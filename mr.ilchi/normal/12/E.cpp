/*
 * in the name of god
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int maxN= 1000+5;

int n;
int rest[maxN], Left[maxN], Right[maxN];
int mat [maxN][maxN];
         
inline void print(){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
            cerr << mat[i][j] << ' ';
        cerr << endl;
    }
//  cerr << "rest: ";
//  for (int i=1;i<=n;i++)
//      cerr << rest[i] << ' ';
    cerr << endl << "***************" << endl;
}
/***********************************/
inline void solve (int s, int e){
    if (s==e){
        rest[1]= s;
        return;
    }
    int mid=(s+e)/2;
    solve (s,mid); 

    int l1=0, l2=0;
    for (int i=s;i<=mid;i++)
        Left[l1++]= i;
    for (int i=mid+1;i<=e;i++)
        Right[l2++]= i;
    if (l1!=l2)
        Right[l2++]= 0;
    
    for (int i=0;i< l2;i ++)
        for (int j= i;j< l2;j ++)
            mat[Right[i]][Right[j]]= mat[Right[j]][Right[i]]= mat[Left[i]][Left[j]];

    if (l1&1){
        for (int i=1;i<=l1;i ++){
            int j= rest[i]+l1;
            if (e < j)
                j=0;
            mat[rest[i]][j]= mat[j][rest[i]]= i;
        }
    }
    for (int i=0;i< l1;i ++){
        int week= (l1&1) ? l1+1 : l1;
        int ii= Left[i];
        for (int j= i;j< l2;j ++){
            int jj= Right[j];
            if (mat[ii][jj])
                continue;
            mat[ii][jj]= mat[jj][ii]= week++;
        }
        for (int j=0;j< i;j ++){
            int jj= Right[j];
            if (mat[ii][jj])
                continue;
            mat[ii][jj]= mat[jj][ii]= week++;
        }
    }
    if (Right[l2-1]==0){
        for (int i=s;i<=e;i ++)
            rest[mat[0][i]]= i;
    }
    
    for (int i=1;i<=n;i++)
        mat[0][i]=mat[i][0]= 0;
}
/*******************************************/
int main (){
    scanf ("%d", &n);
    
    solve (1, n);
    
    for (int i=1;i<= n;i ++){
        for (int j=1;j<= n;j ++)
            printf ("%d ", mat[i][j]);
        printf ("\n");
    }

    return 0;
}