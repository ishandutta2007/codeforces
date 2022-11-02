/*
Iradachi o doko ni butsukeru ka sagashiteru aida ni owaru hi
Sora wa haiiro o shite sono saki wa nanimo mienai
Joushiki butteru yatsu ga waratteru tsugi wa donna uso o iu?
Sore de erareta mono daiji ni kazatteokeru no?
Demo asu e to susumanakya naranai
Dakara kou utau yo

Naiteru kimi koso kodoku na kimi koso
Tadashii yo ningenrashii yo
Otoshita namida ga kou iu yo
Konna ni mo utsukushii uso ja nai hontou no bokura o arigatou

Kanaetai yume ya todokanai yume ga aru koto
Sore jitai ga yume ni nari kibou ni nari hito wa ikiteikeru ndaro
Tobira wa aru soko de matteiru
Dakara te o nobasu yo

Kujiketa kimi ni wa mou ichido tatakaeru tsuyosa to jishin to kono uta o
Otoshita namida ga kou iu yo
Konna ni mo yogorete minikui sekai de deaeta kiseki ni arigatou
*/
#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,lol;
long long a[300010];
char c[1000010];
char d[1000010];
int main()
{
    cin>>i;
    for(j=0;j<i;j++)
    {
        k=0; n=0; m=0; lol=0;
        scanf("%s",&c);
        scanf("%s",&d);
        while(c[n]!='\0')
        {
            if(c[n]==c[n+1])
            {
                if(c[n]==d[m])
                {
                    n++;
                    m++;
                }
                else
                {
                    k++;
                    break;
                }
            }
            else
            {
                if(lol==0 && c[n]!=d[m])
                {
                    k++;
                    break;
                }
                else if(c[n]==d[m])
                {
                    m++;
                    lol++;
                }
                else
                {
                    lol=0;
                    n++;
                }
            }
        }
        while(d[m]!='\0')
        {
            if(d[m]!=c[n-1])
            {
                k++;
                break;
            }
            m++;
        }
        if(k==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        n=0; m=0;
    }
    return 0;
}