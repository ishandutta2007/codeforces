var n,m,i,j,cnt,sum:longint;
    a:array[1..1000,1..1000] of char;
    cnti,cntj:array[1..1000] of longint;
begin
  readln(n,m);
  for i:=1 to n do
  begin
      for j:=1 to m do
      begin
           read(a[i,j]);
           if a[i,j]='*' then
           begin
                inc(cnt);
                inc(cnti[i]);
                inc(cntj[j]);
           end;
      end;
      readln;
  end;
  for i:=1 to n do for j:=1 to m do
    if cnti[i]+cntj[j]-ord(A[i,j]='*')=cnt then
    begin
      writeln('YES');
      writeln(i,' ',j);
      halt;
    end;
  writeln('NO');
end.