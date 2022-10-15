program Project1;

var
  n, a, b, i1, i2, i3, i4, i5, i6, i7, amount, Min: LongInt;
  sum: array [1..6] of LongInt;

function BoolToInt(B: Boolean): LongInt;
begin
  If B then Result := 1 else Result := 0;
end;

begin
  ReadLn(n);
  ReadLn(a);
  ReadLn(b);
  Min := 7;
  For i1 := 1 to 6 do
  begin
    For i2 := 1 to 6 do
    begin
      For i3 := 1 to 6 do
      begin
        For i4 := 1 to 6 do
        begin
          For i5 := 1 to 6 do
          begin
            For i6 := 1 to 6 do
            begin
              For i7 := 1 to 6 do sum[i7] := 0;
              sum[i1] := sum[i1] + a;
              sum[i2] := sum[i2] + a;
              sum[i3] := sum[i3] + a;
              sum[i4] := sum[i4] + a;
              sum[i5] := sum[i5] + b;
              sum[i6] := sum[i6] + b;
              If (sum[1] <= n) and (sum[2] <= n) and (sum[3] <= n) and
                 (sum[4] <= n) and (sum[5] <= n) and (sum[6] <= n) then
              begin
                amount := 6 - BoolToInt(sum[1] = 0) - BoolToInt(sum[2] = 0) - BoolToInt(sum[3] = 0)
                            - BoolToInt(sum[4] = 0) - BoolToInt(sum[5] = 0) - BoolToInt(sum[6] = 0);
                If amount < min then min := amount;
              end;
            end;
          end;
        end;
      end;
    end;
  end;
  WriteLn(min);
end.