#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string S; int RR;

int main()
{
    //freopen ("input.txt","r",stdin);
    //freopen ("output.txt","w",stdout);

    fin >> S >> RR;

    if (S == "front") fout << ((RR == 1) ? "L" : "R");
    else fout << ((RR == 2) ? "L" : "R");

    return 0;
}