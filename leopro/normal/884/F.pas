program project1;

var
  beauty: array [1..100]of LongInt;
  n, sum, changes, i, rem, MaxBeauty, MinBeauty, x: LongInt;
  s: string;
  symbols: array ['a'..'z'] of LongInt;
  c, MaxCh: char;
  Changed: array [1..50] of Boolean;

procedure ReadArray(var a: array of LongInt; n: LongInt);
begin
  For i := 0 to n-1 do
  If i < n-1 then Read(a[i]) else ReadLn(a[i]);
end;

function Min(a, b: LongInt): LongInt;
begin
  If a < b then Result := a else Result := b;
end;

function Max(a: array of LongInt; n: LongInt): LongInt;
begin
  Result := a[0];
  For i := 0 to n-1 do
  If a[i] > Result then Result := a[i];
end;

function ArraySum(a: array of LongInt): LongInt;
begin
  Result := 0;
  For i := 0 to Length(a)-1 do Result := Result + a[i];
end;

begin
  ReadLn(n);
  ReadLn(s);
  ReadArray(beauty, n);
  sum := ArraySum(beauty);
  changes := 0;
  For c := 'a' to 'z' do symbols[c] := 0;
  For i := 1 to 50 do Changed[i] := False;
  MaxBeauty:=Max(beauty, n);
  For i := 1 to n div 2 do
  begin
    If s[i] = s[n-i+1] then
    begin
      Changed[i] := True;
      symbols[s[i]] := symbols[s[i]] + 1;
      sum := sum - min(beauty[i], beauty[n-i+1]);
      changes := changes + 1;
      beauty[i] := MaxBeauty;
      beauty[n-i+1] := MaxBeauty;
    end;
  end;
  rem := symbols['a'];
  For c := 'a' to 'z' do
  If rem <= symbols[c] then
  begin
    rem := symbols[c]; MaxCh:=c;
  end;

  For c := 'a' to 'z' do
  If c <> MaxCh then rem := rem - symbols[c];
  rem := rem;
  While rem > 0 do
  begin
    MinBeauty := 100;
    For i := 1 to n div 2 do
    begin
      If (not Changed[i]) and (s[i] <> MaxCh) and (s[n-i+1] <> MaxCh) and
         ((MinBeauty > beauty[i]) or (MinBeauty > beauty[n-i+1])) then
      begin
        MinBeauty := Min(beauty[i], beauty[n-i+1]);
        x := i;
      end;
    end;
    Changed[x] := True;
    sum := sum - MinBeauty;
    rem := rem - 1;
  end;
  WriteLn(sum);   
end.