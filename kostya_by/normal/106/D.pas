program project1;

const p : array[1..4,1..2] of longint = ((1,0),(-1,0),(0,-1),(0,1));

var
   map : array[1..1000,1..1000] of char;
   sum1, sum2 : array[0..1000,0..1000] of longint;
   l,np : array[1..100000] of longint;
   bool : array[1..26] of boolean;
   x,y : array[1..26] of longint;
   i,j,k,n,m,xn,yn,now,inow,jnow,sum,i1,j1 : longint;
   ch : char;
   ans : string;
   fl : boolean;

function min(a,b : longint):longint;
begin
     if a < b then min:=a else min:=b;
end;

function max(a,b : longint):longint;
begin
     if a > b then max:=a else max:=b;
end;

begin
     readln(n,m);
     for i:=1 to 26 do begin
         x[i]:=-1;
         y[i]:=-1;
     end;
     for i:=1 to n do begin
         for j:=1 to m do begin
             read(map[i,j]);
             if (map[i,j] <> '.') and (map[i,j] <> '#') then begin
                k:=ord(map[i,j]) - 64;
                x[k]:=i;
                y[k]:=j;
             end;
         end;
         readln;
     end;
     for i:=1 to n do begin
         if map[i,1] = '#' then sum1[i,1]:=1 else sum1[i,1]:=0;
         for j:=2 to m do begin
             if map[i,j] = '#' then sum1[i,j]:=sum1[i,j - 1] + 1 else sum1[i,j]:=sum1[i,j - 1];
         end;
     end;
     for j:=1 to m do begin
         if map[1,j] = '#' then sum2[1,j]:=1 else sum2[1,j]:=0;
         for i:=2 to n do begin
             if map[i,j] = '#' then sum2[i,j]:=sum2[i - 1,j] + 1 else sum2[i,j]:=sum2[i - 1,j];
         end;
     end;
     readln(k);
     for i:=1 to k do begin
         read(ch);
         if ch = 'N' then np[i]:=1;
         if ch = 'S' then np[i]:=2;
         if ch = 'W' then np[i]:=3;
         if ch = 'E' then np[i]:=4;
         readln(l[i]);
     end;
     ans:='';
     for i:=1 to 26 do begin
         if x[i] = -1 then continue;
         fl:=true;
         i1:=x[i];
         j1:=y[i];
         for j:=1 to k do begin
             now:=np[j];
             if now = 2 then begin
                inow:=i1 + l[j];
                jnow:=j1;
             end;
             if now = 1 then begin
                inow:=i1 - l[j];
                jnow:=j1;
             end;
             if now = 3 then begin
                inow:=i1;
                jnow:=j1 - l[j];
             end;
             if now = 4 then begin
                inow:=i1;
                jnow:=j1 + l[j];
             end;
             if (inow < 1) or (jnow < 1) or (inow > n) or (jnow > m) then begin
                fl:=false;
                break;
             end;
             if (i1 = inow) then begin
                sum:=sum1[i1,max(j1,jnow)] - sum1[i1,min(j1,jnow) - 1];
             end;
             if (j1 = jnow) then begin
                sum:=sum2[max(i1,inow),j1] - sum2[min(i1,inow) - 1,j1];
             end;
             if sum <> 0 then begin
                fl:=false;
                break;
             end;
             i1:=inow;
             j1:=jnow;
         end;
         if fl then begin
            ans:=ans + chr(i + 64);
         end;
     end;
     {for i:=1 to n do begin
         for j:=1 to m do begin
             write(sum1[i,j],' ');
         end;
         writeln
     end;
     writeln;
     for i:=1 to n do begin
         for j:=1 to m do begin
             write(sum2[i,j],' ');
         end;
         writeln;
     end;
     writeln; }
     if ans = '' then writeln('no solution') else writeln(ans);
end.