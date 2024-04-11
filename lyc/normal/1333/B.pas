var t,n,i1,i:longint;b,a,tong:array[-1..200000] of longint;
begin
  read(t);
  for i1:=1 to t do
  begin
    read(n);tong[1]:=0;tong[-1]:=0;tong[0]:=0; 
    for i:=1 to n do
      read(a[i]);
    for i:=1 to n do
      read(b[i]);
    for i:=1 to n+1 do
    begin
      if i=n+1 then break;
      if b[i]-a[i]<0 then
      begin
        if tong[-1]=0 then
        begin
          writeln('NO');
          break;
        end;
      end;
      if b[i]-a[i]>0 then
      begin
        if tong[1]=0 then
        begin
          writeln('NO');
          break;
        end;
      end;
      tong[a[i]]:=1;
    end;
    if i=n+1 then writeln('YES');
  end;
end.