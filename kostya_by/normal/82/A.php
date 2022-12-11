<?php
    $n = fgets(STDIN);
    $pt = 5;
    while ($n - $pt > 0) {
        $n -= $pt;
        $pt *= 2;
    }
    $pt = $pt / 5;
    $ans = "Howard";
    if ($n <= $pt * 4) $ans = "Rajesh";
    if ($n <= $pt * 3) $ans = "Penny";
    if ($n <= $pt * 2) $ans = "Leonard";
    if ($n <= $pt) $ans = "Sheldon";
    echo $ans;
?>