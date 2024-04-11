#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL mat[2][2];

void input(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> mat[i][j];
        }
    }
}

const double Eps = 1e-12;


double find_res(int a, int b, int c, int d){
    LL coefB = mat[0][0] * a
                 - mat[0][1] * b
                 - mat[1][0] * c
                 + mat[1][1] * d,
       coefA = a*d - b*c,
       coefC = mat[0][0]*mat[1][1] - mat[0][1] * mat[1][0];

    if(coefA == 0){
        if(coefB == 0) return 1e100;
        return abs((double)coefC / coefB);
    }

    double delta = (double)coefB*coefB - 4*(double)coefA*coefC;
    if(delta < -Eps) return 1e100;

    double tt1 = -(double)coefB / (2*coefA),
           tt2 = sqrt(delta) / (2*coefA);

    return min(abs(tt1+tt2), abs(tt1-tt2));
}


int main(){
    input();

    double result = 1e100;

    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            for(int c = -1; c <= 1; c++){
                for(int d = -1; d <= 1; d++){
                    result = min(result, find_res(a,b,c,d));
                }
            }
        }
    }

    cout << setprecision(14) << result << endl;
}