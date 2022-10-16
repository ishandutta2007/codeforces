var a,n,dem,k:longint;
 
{---------------------------------}
function luythua(a:byte):longint;
var i:byte;
tg:longint;
begin
        tg:=1;
        for i:=1 to a do
                tg:=tg*2;
        luythua:=tg;
end;
{---------------------------------}
function somax(x:longint):longint;
var dem:byte;
tg:longint;
begin
        dem:=0;
        tg:=0;
        while tg+5*luythua(dem)<x do
        begin
                tg:=tg+5*luythua(dem);
                inc(dem);
        end;
        somax:=tg;
end;
{-----------------------------------}
function mumax(x:longint):byte;
var dem:byte;
tg:longint;
begin
        tg:=0;
        dem:=0;
        while tg+5*luythua(dem)<x do
        begin
                tg:=tg+5*luythua(dem);
                inc(dem);
        end;
        mumax:=dem;
end;
{-----------------------------------}
begin
        readln(n);
        dem:=mumax(n);
        a:=n-somax(n);
        k:=(a-1+luythua(dem)) div luythua(dem);
        if k=1 then write('Sheldon');
        if k=2 then write('Leonard');
        if k=3 then write('Penny');
        if k=4 then write('Rajesh');
        if k=5 then write('Howard');
        readln
 
end.