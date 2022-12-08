#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N; double R,r;

int main()
{
    scanf ("%d %lf %lf",&N,&R,&r);

    if (r > R) printf ("NO");
    else if (r == R){
        printf (N<=1?"YES":"NO");
    }
    else{
        if (N == 1) printf ("YES");
        else{
            double theta = asin(double(r/(R-r))) - 1e-9;
            double all = theta * N;

            printf ((all<=acos((double)-1))?"YES":"NO");
        }
    }

    return 0;
}