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
 *
 */

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN= 100+5;

char res[MAXN], pre[MAXN];
int n, k;
string name, ord;

inline void setPre (){
    pre[0]= 0;
    char rem= 0;
    for (int i= 1;i< (int)name.size ();i ++){
        while (rem > 0 && name[i]!= name[rem])
            rem= pre[rem-1];
        if (name[i]== name[rem])
            rem ++;
        pre[i]= rem;
    }
}
/****************************************/
int main (){
    cin >> n >> k;
    cin >> name >> ord;
    setPre ();
    
    char match= 0;
    for (int i= 0;i< n;i ++){
        if (i<(int)ord.size() && ord[i]== '1')
            for (int j= 0;j< (int)name.size ();j ++){
                if (res[i+j]!= 0 && res[i+j]!= name[j]){
                    puts ("No solution");
                    return 0;
                }
                res[i+j]= name[j];
            }

        if (res[i]== 0){
            int beg_match= match;
            match= name.size ()+1;
            for (char ch='a'+k-1;ch>= 'a';ch --){
                int tmp= beg_match;
                while (tmp > 0 && name[tmp]!= ch)
                    tmp= pre[tmp-1];
                if (name[tmp]== ch)
                    tmp ++;
                if (tmp < match){
                    match = tmp;
                    res[i]= ch;
                }   
            }
        }
        else{
            while (match > 0 && name[match]!= res[i])
                match= pre[match-1];
            if (name[match]== res[i])
                match ++;
            if (match== (int)name.size () && ord[i-name.size()+1]== '0'){
                puts ("No solution");
                return 0;
            }
            else if (match== (int)name.size())
                match= pre[match-1];
        }
    }
    puts (res);

    return 0;
}