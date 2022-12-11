program project1;

uses math;

var
  start,finish : array[1..2000] of byte;
  hash : array[1..2000,1..2000] of int64;
  ans : array[1..4000000,1..3] of longint;
  now,step : int64;
  i,j,k,n,num,h,t1 : longint;
  st,fn,t,s : ansistring;

procedure sort(l,r : longint);
var
   i,j : longint;
   z,a : longint;
   xy : int64;
begin
     i:=l;
     j:=r;
     a:=(l + r) div 2;
     xy:=hash[ans[a,1],ans[a,2]];
     z:=ans[a,3];
     repeat
           while ((hash[ans[i,1],ans[i,2]] < xy)) or ((hash[ans[i,1],ans[i,2]] = xy) and (ans[i,3] < z)) do inc(i);
           while ((hash[ans[j,1],ans[j,2]] > xy)) or ((hash[ans[j,1],ans[j,2]] = xy) and (ans[j,3] > z)) do dec(j);
           if i <= j then begin
              a:=ans[i,1]; ans[i,1]:=ans[j,1]; ans[j,1]:=a;
              a:=ans[i,2]; ans[i,2]:=ans[j,2]; ans[j,2]:=a;
              a:=ans[i,3]; ans[i,3]:=ans[j,3]; ans[j,3]:=a;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sort(i,r);
     if l < j then sort(l,j);
end;

begin
     randomize;
     readln(t);
     readln(st);
     readln(fn);
     step:=41;
     n:=length(t);
     for i:=1 to n do begin
         now:=0;
         for j:=i to n do begin
             now:=now * step + ord(t[j]) - 96;
             hash[i,j]:=now;
         end;
     end;
     for i:=1 to (n - length(st) + 1) do begin
         s:=copy(t,i,length(st));
         if s = st then start[i]:=1;
     end;
     for i:=1 to (n - length(fn) + 1) do begin
         s:=copy(t,i,length(fn));
         if s = fn then finish[i + length(fn) - 1]:=1;
     end;
     k:=0;
     for i:=1 to n do begin
         for j:=i to n do begin
             if (start[i] = 1) and (finish[j] = 1) and (j - i + 1 >= max(length(st),length(fn))) then begin
                inc(k);
                ans[k,1]:=i;
                ans[k,2]:=j;
                ans[k,3]:=j - i + 1;
             end;
         end;
     end;
     sort(1,k);
     num:=0;
     h:=1;
     t1:=1;
     hash[5,2]:=0;
     ans[k+1,1]:=5;
     ans[k+1,2]:=2;
     ans[k+1,3]:=-1;
     while h < k + 1 do begin
           while (hash[ans[h,1],ans[h,2]] = hash[ans[t1,1],ans[t1,2]]) and (ans[h,3] = ans[t1,3]) do inc(t1);
           h:=t1;
           inc(num);
     end;
     writeln(num);
end.