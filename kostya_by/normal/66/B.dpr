program project1;

var
   a : array[1..1000] of longint;
   i,j,n,ans,now : longint;
begin
     read(n);
     for i:=1 to n do read(a[i]);
     ans:=-1;
     for i:=1 to n do begin
         now:=0;
         j:=i-1;
         while (a[j] <= a[j + 1]) and (j > 0) do begin
               dec(j);
               inc(now);
         end;
         j:=i + 1;
         while (a[j] <= a[j - 1]) and (j <= n) do begin
               inc(j);
               inc(now);
         end;
         now:=now + 1;
         if now > ans then ans:=now;
     end;
     writeln(ans);
end.