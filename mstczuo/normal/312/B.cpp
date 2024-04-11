# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double s = (a/b)/(1-(1-a/b)*(1-c/d));
    printf("%.12lf",s);
}