program DivisiblityOfDifferences;

var
  n, k, m, i, amount, rem: LongInt;
  a, b: array [0..100000] of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

procedure ZeroArray(var a: array of LongInt);
begin
  For i := 0 to Length(a)-1 do a[i] := 0;
end;

procedure SortArray(var a: array of LongInt);
var
  j, k, N, plus1, plus2, x: LongInt;
  b: array of array of LongInt;
  First: Boolean;
begin
  N := 1;
  While N < Length(a) do N := N*2;
  SetLength(b, 2, N);
  For i := 0 to Length(a)-1 do b[0, i] := a[i];
  i := 1;
  x := 0;
  While i < N do
  begin
    For j := 0 to (N div (i*2))-1 do
    begin
      plus1 := 0;
      plus2 := 0;
      For k := 0 to i*2-1 do
      begin
        First := True;
        If (plus2 < i) and (plus1 < i) then
        begin
          If (b[x, j*(i*2)+plus1] < b[x, j*(i*2)+i+plus2]) then First := False;
        end else If (plus2 < i) and (plus1 = i) then First := False;
        If (j*(i*2)+i+plus2 > Length(a)-1) then First := True;
        If (j*(i*2)+plus1 > Length(a)-1) then First := False;

        If First then
        begin
          b[(x+1) mod 2, j*(i*2)+plus1+plus2] := b[x, j*(i*2)+plus1];
          plus1 := plus1+1;
        end else
        begin
          b[(x+1) mod 2, j*(i*2)+plus1+plus2] := b[x, j*(i*2)+i+plus2];
          plus2 := plus2+1;
        end;
      end;
    end;
    x := (x+1) mod 2;
    i := i*2;
  end;
  For i := 0 to Length(a)-1 do a[i] := b[x, i];
end;

begin
  Read(n);  Read(k); ReadLn(m);
  ZeroArray(a);
  ReadArray(a, n);
  For i := 0 to n-1 do
  begin
    b[i] := a[i] mod m;
  end;
  SortArray(b);
  amount := 1;
  For i := 1 to n-1 do
  begin
    If b[i] = b[i-1] then
    begin
      amount := amount + 1
    end else
    begin
      If amount >= k then Break;
      amount := 1;
    end;
  end;

  If (i = n-1) and (amount < k) then
  begin
    WriteLn('No')
  end else
  begin
    rem := b[i-1];
    WriteLn('Yes');
    k := k-1;
    For i := 0 to n-1 do
    begin
      If a[i] mod m = rem then
      begin
        If k < 1 then
        begin
          WriteLn(a[i]);
        end else
        begin
          Write(a[i], ' ');
        end;
        If k = 0 then break;
        k := k - 1;
      end;
    end;
  end;
end.