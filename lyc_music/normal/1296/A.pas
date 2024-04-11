var t,i1,n,i,ans:longint;a:array[0..100000]of longint;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n);ans:=0;
    for i:=1 to n do
    begin
      read(a[i]);
      if a[i] mod 2=1 then
        inc(ans);
    end;
    if n=1 then
      begin
        if ans=1 then writeln('YES') else writeln('NO');
      end
      else
    if ans<>n then
    begin
      if ans>0 then writeln('YES') else writeln('NO');
    end else
      if n mod 2=1 then writeln('YES') else writeln('NO'); 
  end;
end.