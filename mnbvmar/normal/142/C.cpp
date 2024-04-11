#include <bits/stdc++.h>

using namespace std;



const char data[9][9][9][10] = {
{
{"."},
{".."},
{"..."},
{"...."},
{"....."},
{"......"},
{"......."},
{"........"},
{"........."},
},

{
{".","."},
{"..",".."},
{"...","..."},
{"....","...."},
{".....","....."},
{"......","......"},
{".......","......."},
{"........","........"},
{".........","........."},
},

{
{".",".","."},
{"..","..",".."},
{"AAA",".A.",".A."},
{"AAA.",".A..",".A.."},
{"AAA.B",".ABBB",".A..B"},
{"AAA.B.",".ABBB.",".A..B."},
{"AAABCCC",".A.B.C.",".ABBBC."},
{"AAA.BCCC",".ABBB.C.",".A..B.C."},
{"AAABCCC.D",".A.B.CDDD",".ABBBC..D"},
},

{
{".",".",".","."},
{"..","..","..",".."},
{"AAA",".A.",".A.","..."},
{"AAA.",".AB.",".AB.",".BBB"},
{"AAA.B",".ABBB",".A..B","....."},
{"AAABBB",".AC.B.",".AC.B.",".CCC.."},
{"AAABBB.",".AC.BD.",".AC.BD.",".CCCDDD"},
{"AAA.BCCC",".ABBBDC.",".A..BDC.","....DDD."},
{"AAABBBCCC",".AD.BE.C.",".AD.BE.C.",".DDDEEE.."},
},

{
{".",".",".",".","."},
{"..","..","..","..",".."},
{"AAA",".A.",".AB","BBB","..B"},
{"AAA.",".AB.",".AB.",".BBB","...."},
{"AAA.B",".ABBB","CA.DB","CCCD.","C.DDD"},
{"AAA.B.",".ABBB.",".AC.BD","CCCDDD","..C..D"},
{"AAA.B..",".ABBBC.","DA.EBC.","DDDECCC","D.EEE.."},
{"AAA.BCCC",".ABBBDC.","EA.FBDC.","EEEFDDD.","E.FFF..."},
{"AAA.BCCC.",".ABBBDC..","EA.FBDCG.","EEEFDDDG.","E.FFF.GGG"},
},

{
{".",".",".",".",".","."},
{"..","..","..","..","..",".."},
{"AAA",".A.",".AB","BBB","..B","..."},
{"AAA.",".AB.",".AB.","CBBB","CCC.","C..."},
{"AAA.B",".ABBB",".AC.B","CCCD.","..CD.","..DDD"},
{"AAA.B.",".ABBB.",".A.CB.","DCCCE.","DDDCE.","D..EEE"},
{"AAABCCC",".A.B.C.","DABBBCE","DDDFEEE","DFFF..E","...F..."},
{"AAA.BCCC",".ABBBDC.",".AE.BDC.","EEEFDDDG","..EF.GGG","..FFF..G"},
{"AAA.BCCC.",".ABBB.C..",".A.DBEC..","FDDDGEEEH","FFFDGEHHH","F..GGG..H"},
},

{
{".",".",".",".",".",".","."},
{"..","..","..","..","..","..",".."},
{"AAA",".A.",".AB","BBB",".CB",".C.","CCC"},
{"AAA.",".AB.",".AB.","CBBB","CCCD","CDDD","...D"},
{"AAA.B",".ABBB",".AC.B","CCCD.",".ECD.",".EDDD","EEE.."},
{"AAA.B.",".ABBB.",".AC.BD","CCCDDD",".EC.FD",".EFFF.","EEE.F."},
{"AAABCCC",".A.B.C.","DABBBCE","DDDFEEE","DG.F.HE",".GFFFH.","GGG.HHH"},
{"AAA.BBB.",".ACCCBD.",".AEC.BD.","EEECFDDD","G.EHFFFI","GGGHFIII","G.HHH..I"},
{"AAA.BC...",".ABBBCCCD","EA.FBCDDD","EEEF.GGGD","EHFFFIGJ.",".H.IIIGJ.","HHH..IJJJ"},
},

{
{".",".",".",".",".",".",".","."},
{"..","..","..","..","..","..","..",".."},
{"AAA",".A.",".AB","BBB",".CB",".C.","CCC","..."},
{"AAA.",".AB.",".AB.","CBBB","CCCD","CDDD","...D","...."},
{"AAA.B",".ABBB","CA.DB","CCCD.","CEDDD",".EFFF","EEEF.","...F."},
{"AAA.B.",".ABBB.",".AC.BD","CCCDDD","..CE.D","FEEEG.","FFFEG.","F..GGG"},
{"AAAB..C",".A.BCCC","DABBBEC","DDDEEE.","DFFF.EG",".HFIGGG",".HFIIIG","HHHI..."},
{"AAA.BCCC",".ABBBDC.","EA.FBDC.","EEEFDDDG","EHFFFGGG",".HIII.JG","HHHIJJJ.","...I..J."},
{"AAABBB..C",".AD.BECCC",".AD.BEEEC","FDDDGEHHH","FFFIGGGH.","FJ.IGK.HL",".JIIIKLLL","JJJ.KKK.L"},
},

{
{".",".",".",".",".",".",".",".","."},
{"..","..","..","..","..","..","..","..",".."},
{"AAA",".A.",".AB","BBB","C.B","CCC","C.D","DDD","..D"},
{"AAA.",".AB.",".AB.","CBBB","CCCD","CDDD","EEED",".E..",".E.."},
{"AAA.B",".ABBB","CA.DB","CCCD.","CEDDD",".EEEF","GEFFF","GGG.F","G...."},
{"AAA.B.",".ABBB.",".AC.BD","CCCDDD","E.CF.D","EEEF..","EGFFFH",".G.HHH","GGG..H"},
{"AAA.B..",".ABBBC.",".AD.BC.","DDDECCC","F.DEEEG","FFFEGGG","FHIIIJG",".H.I.J.","HHHIJJJ"},
{"AAA.BCCC",".ABBBDC.","EA.FBDC.","EEEFDDDG","EHFFFGGG",".HHHIIIG","JHKKKIL.","JJJK.IL.","J..K.LLL"},
{"AAA.BCCC.",".ABBB.CD.",".AE.BFCD.","EEEFFFDDD","G.E.HFIII","GGGJHHHI.","GK.JHL.IM",".KJJJLMMM","KKK.LLL.M"},
}

};


int main(){
    int N, M;
    scanf("%d%d", &N, &M);

    int numLaid = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++){
            char c = data[N-1][M-1][i][j];
            if(c >= 'A') numLaid = max(numLaid, c-'A'+1);
        }

    printf("%d\n", numLaid);

    for(int i = 0; i < N; i++)
        printf("%s\n", data[N-1][M-1][i]);
}