{$APPTYPE CONSOLE}
uses SysUtils, Math;

var
  m, n, i, j, lr : integer;
  a : array[1..150,1..150] of char;
  have : array[1..150] of boolean;
  st, en : array[1..150] of integer;
  f : array[1..150,1..150] of integer;

begin
  readln(m,n);
  for i:=1 to m do
  begin
    for j:=1 to n do read(a[i,j]);
    readln;
  end;
  lr := 0;
  for i:=1 to m do st[i] := 1000;
  for i:=1 to m do for j:=1 to n do if a[i,j] = 'W' then
  begin
    have[i] := true;
    st[i] := min(st[i], j);
    en[i] := j;
    if have[i] then lr := i;
  end;
  FillChar(f,SizeOf(f),$1f);
  f[1,1] := 0;
  for i:=1 to m do
  begin
    if i mod 2 = 1 then
    for j:=1 to n do if (i<>1) or (j<>1) then
    begin
        if (j > 1) then f[i,j] := min(f[i,j], f[i,j-1] + 1);
        if (i > 1) and ((j <= st[i-1]) or not have[i-1]) and ((j <= st[i]) or not have[i]) then f[i,j] := min(f[i,j], f[i-1,j] + 1);
    end;
    if i mod 2 = 0 then
    for j:=n downto 1 do if (i<>1) or (j<>1) then
      begin
        if (j < n) then f[i,j] := min(f[i,j], f[i,j+1] + 1);
        if (i > 1) and ((j >= en[i-1]) or not have[i-1]) and ((j >= en[i]) or not have[i]) then f[i,j] := Min(f[i,j], f[i-1,j]+1);
      end
  end;

  {for i:=1 to m do
  begin
    for j:=1 to n do write(f[i,j],' ');
    writeln;
  end;}

  if lr = 0 then writeln(0)
  else
  begin
    if lr mod 2 = 0 then writeln(f[lr,st[lr]])
    else writeln(f[lr,en[lr]]);
  end;
end.